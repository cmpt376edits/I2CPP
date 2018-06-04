#ifndef I2C_LIBRARY_H
#define I2C_LIBRARY_H

#include <cstdint>
#include <string>
#include <map>


namespace i2cpp
{
    class I2CNetwork
    {
        public:
            I2CNetwork(I2CNetwork const&) = delete;
            void operator=(I2CNetwork const&) = delete;

            static int open_adapter(int bus);
            static int open_adapter(std::string filename);
            static std::size_t write_i2c(int adapter, int address, uint8_t* buffer, std::size_t length);
            static std::size_t read_i2c(int adapter, int address, uint8_t* buffer, std::size_t length);

        private:
            I2CNetwork();
            ~I2CNetwork();
            static I2CNetwork& instance();

            std::map<std::string, int> fds;
            std::map<int, uint8_t> regs;

            std::size_t _write(int adapter, int address, uint8_t* buffer, std::size_t length);
            std::size_t _read(int adapter, int address, uint8_t* buffer, std::size_t length);
            void _set_address(int bus, int address);
    };
}

#endif