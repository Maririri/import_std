module greeting;

import std;

namespace demo
{
    void greet(std::string_view who)
    {
        using namespace std::chrono;
        auto today = floor<days>(system_clock::now());

        std::cout << std::format("[{:%F}] Hello, {}!\n", today, who);
    }
}
