import std;

void hello_world(std::string const& name)
{
    std::cout << "Hello World! My name is " << name << std::endl;
}

double average_of(std::span<const int> numbers)
{
    using std::ranges::fold_left;
    return numbers.empty() ? 0.0
         : static_cast<double>(fold_left(numbers, 0, std::plus{}))
           / numbers.size();
}

void demo_ranges()
{
    std::vector data{ 1, 2, 3, 4, 5 };

    std::cout << std::format("Average value: {}\n", average_of(data));

    auto even = data | std::views::filter([](int v) { return v % 2 == 0; });

    std::cout << "Even numbers:";
    for (int v : even) std::cout << ' ' << v;
    std::cout << '\n';
}
