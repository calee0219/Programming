/**
 * Created by calee0219 on 11/1/16.
 */
/// <reference path="jquery.d.ts" />
var State;
(function (State) {
    State[State["Init"] = 0] = "Init";
    State[State["Num"] = 1] = "Num";
    State[State["Opt"] = 2] = "Opt";
    State[State["Dot"] = 3] = "Dot";
})(State || (State = {}));
var Mode;
(function (Mode) {
    Mode[Mode["Hex"] = 0] = "Hex";
    Mode[Mode["Dec"] = 1] = "Dec";
    Mode[Mode["Oct"] = 2] = "Oct";
    Mode[Mode["Bin"] = 3] = "Bin";
})(Mode || (Mode = {}));
var str = "";
var ans = "";
var buff = "0";
var sta = State.Init;
var mode = Mode.Dec;
var isDiv = false;
var checkNum = new RegExp('[0123456789ABCDEF]');
function init() {
    isDiv = false;
    str = "";
    ans = "";
    buff = "0";
    sta = State.Init;
}
function numToQue() {
    var tmpStr = $(this).text();
    if (sta === State.Init) {
        str = "";
        ans = "";
        buff = "";
    }
    if (buff === "0")
        buff = tmpStr;
    else if (buff === "-0")
        buff = "-" + tmpStr;
    else
        buff += tmpStr;
    sta = State.Num;
    display();
}
function optToQue() {
    var tmpStr = $(this).text();
    var tmpOpt = $(this).attr('id');
    var opt = checkOpt(tmpOpt);
    isDiv = (opt === "/");
    if (sta === State.Init || eval(toDec(buff)) === 0) {
        if (eval(toDec(buff)) !== 0) {
            str = buff + tmpStr;
            ans = toDec(buff) + opt;
            sta = State.Opt;
            buff = "0";
        }
        else if (tmpOpt === "minu") {
            plusMin();
        }
    }
    else if (sta === State.Num) {
        str += buff + tmpStr;
        ans += toDec(buff) + opt;
        sta = State.Opt;
        buff = "0";
    }
    else if (sta === State.Opt) {
        str = str.slice(0, -1) + tmpStr;
        ans = ans.slice(0, -1) + opt;
        sta = State.Opt;
        buff = "0";
    }
    display();
}
function toDec(num) {
    return cType(num, mode, Mode.Dec);
    //if(num.slice(0,1) === "-") return "-"+Number(head(mode)+num.slice(1,num.length));
    //return eval(head(mode)+num);
}
function checkOpt(opt) {
    if (opt === 'plus')
        return '+';
    if (opt === 'minu')
        return '-';
    if (opt === 'muti')
        return '*';
    if (opt === 'divi')
        return '/';
    if (opt === 'modu')
        return '%';
}
function head(mo) {
    if (mo === Mode.Bin)
        return "0b";
    if (mo === Mode.Oct)
        return "0o";
    if (mo === Mode.Dec)
        return "";
    if (mo === Mode.Hex)
        return "0x";
}
function plusMin() {
    if (buff.substr(0, 1) === "-")
        buff = buff.substr(1, buff.length);
    else
        buff = "-" + buff;
    sta = State.Num;
    display();
}
function clear() {
    init();
    display();
}
function clearNum() {
    while (sta === State.Num || sta === State.Dot)
        backspace();
}
function equal() {
    if (isDiv && eval(toDec(buff)) === 0)
        Err();
    buff = cType(operate(), Mode.Dec, mode);
    ans = "";
    str = "";
    isDiv = false;
    sta = State.Init;
    display();
}
function operate() {
    var tmpAns = ans + toDec(buff);
    if (sta === State.Opt)
        tmpAns = ans.slice(0, -1);
    tmpAns = eval(tmpAns) + "";
    if (tmpAns.length === 0)
        tmpAns = "0";
    return tmpAns;
}
function display() {
    console.log("buff ", buff, " |len ", buff.length);
    console.log("ans ", ans, " |len ", ans.length);
    console.log("str ", str, " |len ", str.length);
    // Function
    if (str.length === 0)
        $("#func").text(buff);
    else if (sta === State.Opt)
        $("#func").text(str);
    else
        $("#func").text(str + buff);
    var tmpAns = operate();
    if (tmpAns.length === 0)
        tmpAns = "0";
    $(".buff").text(buff);
    $("#hex").text(cType(tmpAns, Mode.Dec, Mode.Hex));
    $("#dec").text(cType(tmpAns, Mode.Dec, Mode.Dec));
    $("#oct").text(cType(tmpAns, Mode.Dec, Mode.Oct));
    $("#bin").text(cType(tmpAns, Mode.Dec, Mode.Bin));
}
function cType(num, mof, mot) {
    if (num.slice(0, 1) === "-") {
        if (mot === Mode.Bin)
            return "-" + Number(head(mof) + num.substr(1, num.length)).toString(2);
        if (mot === Mode.Oct)
            return "-" + Number(head(mof) + num.substr(1, num.length)).toString(8);
        if (mot === Mode.Dec)
            return "-" + Number(head(mof) + num.substr(1, num.length)).toString(10);
        if (mot === Mode.Hex)
            return "-" + Number(head(mof) + num.substr(1, num.length)).toString(16).toUpperCase();
    }
    else {
        if (mot === Mode.Bin)
            return Number(head(mof) + num).toString(2);
        if (mot === Mode.Oct)
            return Number(head(mof) + num).toString(8);
        if (mot === Mode.Dec)
            return Number(head(mof) + num).toString(10);
        if (mot === Mode.Hex)
            return Number(head(mof) + num).toString(16).toUpperCase();
    }
}
function Err() {
    window.alert("You can't divide 0!!!");
    $("#func").text("Error");
    $("#hex").text("Error");
    $("#dec").text("Error");
    $("#oct").text("Error");
    $("#bin").text("Error");
    clear();
}
function backspace() {
    if (buff.length > 1 && buff !== "0") {
        buff = buff.slice(0, -1);
        sta = State.Num;
    }
    else if (buff.length === 1 && buff !== "0") {
        buff = "0";
        sta = State.Opt;
        if (ans === "")
            sta = State.Init;
    }
    else {
        buff = "";
        str = str.slice(0, -1);
        ans = ans.slice(0, -1);
        while (checkNum.test(ans.slice(-1))) {
            buff = ans.slice(-1) + buff;
            str = str.slice(0, -1);
            ans = ans.slice(0, -1);
        }
        buff = cType(buff, Mode.Dec, mode);
        sta = State.Num;
    }
    if (buff.length === 0)
        buff = "0";
    display();
}
function changeMode() {
    equal();
    if (mode === Mode.Hex) {
        mode = Mode.Dec;
        $("#inputMode").text("Dec");
        $(".hex").addClass('disabled');
        $(".hex").prop('disabled', true);
        $(".dec").removeClass('disabled');
        $(".dec").prop('disabled', false);
        $(".oct").removeClass('disabled');
        $(".oct").prop('disabled', false);
        buff = cType(buff, Mode.Hex, mode);
    }
    else if (mode === Mode.Dec) {
        mode = Mode.Oct;
        $("#inputMode").text("Oct");
        $(".hex").addClass('disabled');
        $(".hex").prop('disabled', true);
        $(".dec").addClass('disabled');
        $(".dec").prop('disabled', true);
        $(".oct").removeClass('disabled');
        $(".oct").prop('disabled', false);
        buff = cType(buff, Mode.Dec, mode);
    }
    else if (mode === Mode.Oct) {
        mode = Mode.Bin;
        $("#inputMode").text("Bin");
        $(".hex").addClass('disabled');
        $(".hex").prop('disabled', true);
        $(".dec").addClass('disabled');
        $(".dec").prop('disabled', true);
        $(".oct").addClass('disabled');
        $(".oct").prop('disabled', true);
        buff = cType(buff, Mode.Oct, mode);
    }
    else if (mode === Mode.Bin) {
        mode = Mode.Hex;
        $("#inputMode").text("Hex");
        $(".hex").removeClass('disabled');
        $(".hex").prop('disabled', false);
        $(".dec").removeClass('disabled');
        $(".dec").prop('disabled', false);
        $(".oct").removeClass('disabled');
        $(".oct").prop('disabled', false);
        buff = cType(buff, Mode.Bin, mode);
    }
    display();
}
function main() {
    $(".button.num").click(numToQue);
    $(".button.opt").click(optToQue);
    //$(".button.dot").click(dotToQue);
    $(".button.c").click(clear);
    $(".button.ce").click(clearNum);
    $(".button.equ").click(equal);
    $(".button.mode").click(changeMode);
    $(".button.pm").click(plusMin);
    $(".button.bs").click(backspace);
    //$(".lBracket").click(lBraToQue);
    //$(".rBracket").click(rBracket);
}
$(document).ready(main);
//# sourceMappingURL=calculator.js.map