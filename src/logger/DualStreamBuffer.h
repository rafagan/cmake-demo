#ifndef DUALSTREAMBUFFER_H
#define DUALSTREAMBUFFER_H

#include <fstream>
#include <streambuf>

class DualStreamBuffer final : public std::streambuf {
private:
    std::streambuf* sb1;
    std::streambuf* sb2;
protected:
    int overflow(int c) override {
        if (const auto ch = static_cast<char>(c); sb1->sputc(ch) == EOF || sb2->sputc(ch) == EOF) return EOF;
        return c;
    }

    int sync() override {
        return (sb1->pubsync() == 0 && sb2->pubsync() == 0) ? 0 : -1;
    }
public:
    DualStreamBuffer(std::streambuf* sb1, std::streambuf* sb2)
        : sb1(sb1), sb2(sb2) {}

};
#endif // DUALSTREAMBUFFER_H
