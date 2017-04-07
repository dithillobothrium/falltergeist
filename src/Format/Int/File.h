/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2012-2015 Falltergeist developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FALLTERGEIST_FORMAT_INT_FILE_H
#define FALLTERGEIST_FORMAT_INT_FILE_H

// C++ standard includes
#include <map>
#include <string>
#include <vector>

// Falltergeist includes
#include "../../Format/Dat/Item.h"
#include "../../Format/Dat/Stream.h"

// Third party includes

namespace Falltergeist
{
namespace Format
{
namespace Int
{
class Procedure;

class File : public Dat::Item
{
public:
    File(Dat::Stream&& stream);
    virtual ~File();

    // TODO: return by reference
    std::vector<Procedure*>* procedures();
    Procedure* procedure(std::string name);

    std::map<unsigned int, std::string>* identifiers();
    std::map<unsigned int, std::string>* strings();

    // current position in script file
    unsigned int position();
    // set current position in script file
    void setPosition(unsigned int);
    // the size of script file
    uint32_t size();
    // read the next opcode
    uint16_t readOpcode();
    // read the next value
    uint32_t readValue();

protected:
    Dat::Stream _stream;

    // TODO: replace with vector of objects
    std::vector<Procedure*> _procedures;

    std::map<unsigned int, std::string> _functions;
    std::vector<unsigned int> _functionsOffsets;
    std::map<unsigned int, std::string> _identifiers;
    std::map<unsigned int, std::string> _strings;
};

}
}
}
#endif // FALLTERGEIST_FORMAT_INT_FILE_H
