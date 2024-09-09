#include <kmx/mib/MIBLexer.h>
#include <kmx/mib/MIBParser.h>

int main(const int argc, const char* const argv[]) noexcept
{
    if (argc == 2u)
        try
        {
            const auto filename = argv[1u];
            std::ifstream input(filename);
            if (input.is_open())
            {
                antlr4::ANTLRInputStream inputStream(input);
                kmx::mib::MIBLexer lexer(&inputStream);
                antlr4::CommonTokenStream tokens(&lexer);
                kmx::mib::MIBParser parser(&tokens);

                // Parse the input using the top rule (e.g., "program")
                auto* tree = parser.data();

                // Check if there were any syntax errors
                if (parser.getNumberOfSyntaxErrors() == 0u)
                    std::cout << tree->toStringTree(&parser) << std::endl;
                else
                    std::cout << "Parsing failed with " << parser.getNumberOfSyntaxErrors() << " syntax errors." << std::endl;
            }
            else
                std::cout << "Failed to open file " << filename << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << ex.what() << std::endl;
        }
    else
        std::cout << "param: <mib-file-path>" << std::endl;

    return 0;
}
