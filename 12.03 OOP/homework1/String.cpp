#include "String.h"
#include <algorithm> 

void String::copyFrom(const String& other) {
    length = other.length;
    data = new char[length + 1];
    std::copy(other.data, other.data + length, data);
    data[length] = '\0';
}

void String::moveFrom(String&& other) noexcept {
    data = other.data;
    length = other.length;
    other.data = nullptr;
    other.length = 0;
}

void String::free() {
    delete[] data;
}

String::String() : data(nullptr), length(0) {
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* str) : length(std::strlen(str)) {
    data = new char[length + 1];
    std::copy(str, str + length, data);
    data[length] = '\0';
}

String::String(const String& other) {
    copyFrom(other);
}

String::String(String&& other) noexcept {
    moveFrom(std::move(other));
}

String::~String() {
    free();
}

String& String::operator=(const String& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

String String::operator*(const String& other) const {
    bool added[256] = { false };
    bool inOther[256] = { false };
    for (size_t i = 0; i < other.length; ++i) {
        inOther[static_cast<unsigned char>(other.data[i])] = true;
    }

    char* result = new char[length + 1];
    size_t pos = 0;
    for (size_t i = 0; i < length; ++i) {
        unsigned char ch = static_cast<unsigned char>(data[i]);
        if (inOther[ch] && !added[ch]) {
            result[pos++] = data[i];
            added[ch] = true;
        }
    }
    result[pos] = '\0';
    String res(result);
    delete[] result;
    return res;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
    if (s.data) os << s.data;
    return os;
}
