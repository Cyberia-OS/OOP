#pragma once

#include <iostream>

class String {
private:
    char* data;
    size_t length;

    void copyFrom(const String& other);
    void moveFrom(String&& other) noexcept;
    void free();

public:
    String();
    String(const char* str);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;

    String operator*(const String& other) const;

    friend std::ostream& operator<<(std::ostream& os, const String& s);
};
