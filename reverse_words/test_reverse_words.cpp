#include <gtest/gtest.h>
#include <algorithm>

// Сначала пытался целиком слова переставлять, а потом подумал нафига?
// Можно же перевернуть все, а потом перевернуть слова
// Что по сложности (О - большое) не скажу, но зато без дополнительной памяти
// Для подсчета сложности можно соорудить кастомный итератор, который будет считать чило инкрементов/декрементов (в глобальной переменной например)

// Pass as copy, not reference
std::string reverseWords(std::string s) {
    std::reverse(std::begin(s), std::end(s));

    auto head = std::begin(s);
    for (;;) {
        auto tail = std::find(head, std::end(s), ' ');
        std::reverse(head, tail);
        if (tail != std::end(s)) {
            head = std::next(tail);
        }
        else {
            break;
        }
    }

    return s;
}


TEST(reverseWords, original) {
    std::string input = "one two three";
    std::string expected = "three two one";
    std::string result = reverseWords(input);
    ASSERT_EQ(result, expected);
}

TEST(reverseWords, oneWord) {
    std::string input = "onetwothree";
    std::string expected = "onetwothree";
    std::string result = reverseWords(input);
    ASSERT_EQ(result, expected);
}

// Что должно быть не заданно, тест для проверки что не алгоритм упадет на таких данных
TEST(reverseWords, endSpace) {
    std::string input = "one two three ";
    std::string expected = " three two one";
    std::string result = reverseWords(input);
    ASSERT_EQ(result, expected);
}
