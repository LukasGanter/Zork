#include <cstdint>
#include <iostream>
#include <thread>
#include <conio.h>
#include "world.h"
#include "tokenizer.h"

#define BACKSPACE "\033[D\033[K"

int main()
{

    char key;
    std::string input;

	std::cout << "Welcome to Zork!\n\n";

    using frame_duration = std::chrono::duration<int64_t, std::ratio<1, 5>>;  // 5Hz

    World world;

    while (true)
    {

        if (_kbhit() != 0)
        {
            key = _getch();
            if (key == '\b') // backspace
            {
                if (input.length() > 0)
                {
                    input.pop_back();
                    std::cout << BACKSPACE;
                }
            }
            else if (key != '\r') // char entered
            {
                input += key;
                std::cout << key;
            }
            else {  // enter pressed
                std::cout << "\n";
                std::vector<OrderTokens> order_tokens;
                std::vector<ValueTokens> value_tokens;
                Tokenizer::tokenize(input, order_tokens, value_tokens);
                input = "";
            }
        }

        if (input.length() == 0) {
            std::this_thread::sleep_for(frame_duration{ 1 });
            world.tick();
        }
    }

	return 0;
}