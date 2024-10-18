#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    int counter =20;
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.add_option("-C,--count", counter, "Counter ist dabei");
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    fmt::print("Counter value: {}\n", counter);
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    fmt::print("value of argc: {}!\n", argc);
    fmt::print("value of argv[0]: {}!\n", argv[0]);
    fmt::print("The value of counter is: {}!\n", counter);

    std::vector<unsigned int> values;
    fmt::print("Elements in values, {}!\n", values.size());
    values.push_back(42);
    values.push_back(4711);
    values.push_back(11);
    fmt::print("Elements in values, {}!\n", values.size());
    for(int i = 0; i < values.size(); i++)
    {
        fmt::print("Element at index {}: {}\n", i, values[i]);
    }
    for(const unsigned int & value : values)
    {
        fmt::print("Value of Element {}\n", value);
    }

    /* INSERT YOUR CODE HERE */

    return 0; /* exit gracefully*/
}
