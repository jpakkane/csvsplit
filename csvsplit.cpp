/*
 * Copyright (c) 2021 Jussi Pakkanen
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <psplit.hpp>
#include <charconv>
#include <cstdio>

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("%s input.csv\n", argv[0]);
        return 1;
    }
    std::vector<std::vector<int>> matrix;
    // If we had coroutines, copying would not be necessary
    for(const auto &line: psplit::split_file_copy(argv[1])) {
        std::vector<int> row;
        for(const auto &item: psplit::split_copy(line, ',', psplit::Empties::Drop)) {
            int i;
            // As this is sample code, ignore errors.
            std::from_chars(item.data(), item.data()+item.length(), i);
            row.push_back(i);
        }
        matrix.emplace_back(std::move(row));
    }
    printf("The file has %d rows.\n", (int)matrix.size());
    for(const auto &row: matrix) {
        for(auto c: row) {
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}
