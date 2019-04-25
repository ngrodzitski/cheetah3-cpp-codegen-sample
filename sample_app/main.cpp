#include <iostream>
#include <array>

#include <custom_protocol/message_header.hpp>

int main()
{
    std::array< char, 16 > buffer;

    {
        custom_protocol::message_header_writer_t h{ buffer };
        h.msg_type( 42 );
        h.version( 1 );
        h.length( 64 );
        h.checksum( 0xFFFFFFFFUL );
    }

    {
        custom_protocol::message_header_reader_t h{ buffer };

        std::cout << "Header:\n"
                  "\tmsg_type : " << h.msg_type() << "\n"
                  "\tversion  : " << h.version() << "\n"
                  "\tlength   : " << h.length() << "\n"
                  "\tchecksum : " << h.checksum() << std::endl;
    }

    return 0;
}
