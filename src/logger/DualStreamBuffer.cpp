#include "DualStreamBuffer.h"

DualStreamBuffer::DualStreamBuffer(std::streambuf* sb1, std::streambuf* sb2)
    : sb1(sb1), sb2(sb2) {}

int DualStreamBuffer::overflow(int c) {
    if (const auto ch = static_cast<char>(c); sb1->sputc(ch) == EOF || sb2->sputc(ch) == EOF) {
        return EOF;
    }
    return c;
}

int DualStreamBuffer::sync() {
    return (sb1->pubsync() == 0 && sb2->pubsync() == 0) ? 0 : -1;
}