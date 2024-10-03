#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <random>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis = std::uniform_int_distribution<>(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static auto gen = std::mt19937(std::random_device{}());
    return select_randomly(start, end, gen);
}

class Parrot
{
private:
    std::vector<std::string> phrases;

public:
    Parrot(std::vector<std::string>&);
    void say();
    void say(const unsigned int&);
    void addPhrase(std::string&);
    void addPhrases(std::vector<std::string>&);
};

Parrot::Parrot(std::vector<std::string>& _phrases)
{
    this->phrases = _phrases;
}

void Parrot::addPhrase(std::string& newPhrase)
{
    this->phrases.push_back(newPhrase);
}

void Parrot::addPhrases(std::vector<std::string>& newPhrases){
    this->phrases.insert(this->phrases.begin(), newPhrases.begin(), newPhrases.end());
}

void Parrot::say()
{
    std::string phrase = *select_randomly(this->phrases.begin(), this->phrases.end());
    std::cout << phrase << std::endl;
}

void Parrot::say(const unsigned int &repeatCount)
{
    for (unsigned int i = 0; i < repeatCount - 1; ++i)
        std::cout << *select_randomly(this->phrases.begin(), this->phrases.end()) << "\n";
    if (repeatCount > 0)
        std::cout << *select_randomly(this->phrases.begin(), this->phrases.end()) << std::endl;
}

int main()
{
    std::vector<std::string> initialPhrases = {"Hello World!", "a", "b"};
    auto parrot = Parrot(initialPhrases);
    // parrot.say(5);
    std::vector<std::string> newPhrases = {"c", "d"};
    parrot.addPhrases(newPhrases);
    parrot.say(5);

    return 0;
}