#include <iostream>
#include <vector>
#include <cstdint>

std::uint8_t getu8(const std::vector<std::uint8_t>& vec, size_t index){
    return vec.at(index);
}

std::uint16_t getu16(const std::vector<std::uint8_t>& vec, size_t index){
    return (static_cast<std::uint16_t>(vec[index + 1]) << 8) + vec[index];
}

std::uint32_t getu32(const std::vector<std::uint8_t>& vec, size_t index){
    return (static_cast<std::uint32_t>(getu16(vec, index + 2)) << 16) + getu16(vec, index);
}

std::uint64_t getu64(const std::vector<std::uint8_t>& vec, size_t index){
    return (static_cast<std::uint64_t>(getu32(vec, index + 4)) << 32) + getu32(vec, index);
}

void setu8(std::vector<std::uint8_t>& vec, std::uint8_t value, size_t index){
    vec[index] = value;
}

void setu16(std::vector<std::uint8_t>& vec, std::uint16_t value, size_t index){
    vec[index + 1] = value >> 8;
    vec[index] = value;
}

void setu32(std::vector<std::uint8_t>& vec, std::uint32_t value, size_t index){
    setu16(vec, value >> 16, index + 2);
    setu16(vec, value, index);
}

void setu64(std::vector<std::uint8_t>& vec, std::uint64_t value, size_t index){
    setu32(vec, value >> 32, index + 4);
    setu32(vec, value, index);
}

bool getbool(const std::vector<std::uint8_t>& vec, size_t index) {
    return vec.at(index) % 2;
}

void setbool(std::vector<std::uint8_t>& vec, bool val, size_t index) {
    vec[index] = val;
}


struct Person{
    std::uint8_t age;
    std::uint8_t weight;
    std::uint16_t birth;
};

Person getP(const std::vector<std::uint8_t>& vec, size_t index){
    std::uint8_t age = getu8(vec, index);
    std::uint8_t weight = getu8(vec, index + 1);
    std::uint16_t birth = getu16(vec, index + 2);
    return {age, weight, birth};
};

void setP(std::vector<std::uint8_t>& vec, const Person& p, size_t index){
    setu8(vec, p.age, index);
    setu8(vec, p.weight, index + 1);
    setu16(vec, p.birth, index + 2);
};


std::vector<std::uint16_t> 


int main(){
    std::vector<std::uint8_t> memory(256,0);

    Person p({0x12, 0x50, 0x07e8});
    setP(memory, p, 0);
    Person p2 = getP(memory, 0);
    std::cout << (int)p2.age << ", " << (int)p2.weight << ", " << (int)p2.birth << std::endl;
}

