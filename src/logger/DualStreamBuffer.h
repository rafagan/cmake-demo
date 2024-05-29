#ifndef DUALSTREAMBUFFER_H
#define DUALSTREAMBUFFER_H

#include <fstream>

class DualStreamBuffer final : public std::streambuf {
private:
    std::streambuf* sb1;
    std::streambuf* sb2;
protected:
    int overflow(int c) override;
    int sync() override;
public:
    DualStreamBuffer(std::streambuf* sb1, std::streambuf* sb2);
};

#endif // DUALSTREAMBUFFER_H
