#include <bits/stdc++.h>
#include <msgpack.hpp>
using namespace std;

char line[100010];
char v[100010];

int main()
{
	//std::ifstream ifs("input.txt", std::ifstream::in);
    //std::stringstream buffer;
    //buffer << ifs.rdbuf();
    //msgpack::unpacked upd;
    //msgpack::unpack(upd, buffer.str().data(), buffer.str().size());
    //std::cout << upd.get() << std::endl;
	msgpack::sbuffer buffer;

        msgpack::packer<msgpack::sbuffer> pk(&buffer);
        pk.pack(std::string("Log message ... 1"));
        pk.pack(std::string("Log message ... 2"));
        pk.pack(std::string("Log message ... 3"));

        // deserializes these objects using msgpack::unpacker.
        msgpack::unpacker pac;

        // feeds the buffer.
        pac.reserve_buffer(buffer.size());
        memcpy(pac.buffer(), buffer.data(), buffer.size());
        pac.buffer_consumed(buffer.size());

        // now starts streaming deserialization.
        msgpack::object_handle oh;
        while(pac.next(oh)) {
            std::cout << oh.get() << std::endl;
        }
}
