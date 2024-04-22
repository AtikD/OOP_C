#pragma once
#include <iostream>
#include <Windows.h>
#include "archive.hpp"

/*                     —À”∆≈¡Õ€≈/¬—œŒÃŒ√¿“≈À‹Õ€≈ ‘”Õ ÷»»                     */

namespace InputSystem {
    enum InsertMode { Back, Front, OneValue, SeveralValues };
    enum RemoveMode {rBack, rFront, Erase, rAll, rFirst, rLast, rIndex};
    enum FindMode { fall, ffirst, flast };

    template <typename T>
    T* insert(size_t& n, size_t& pos, InputSystem::InsertMode& mode) noexcept {
        T* value = nullptr;
        int user;
        std::cout << "Choose insert mode:\n";
        std::cout << "1 - to the back,\n";
        std::cout << "2 - to the front,\n";
        std::cout << "3 - at given position.\n";
        std::cout << "Your choose: ";
        std::cin >> user;
        if (user == 1) { mode = Back; }
        if (user == 2) { mode = Front; }
        if (user == 3) {
            std::cout << "How many values need to insert:\n";
            std::cout << "1 - one value,\n";
            std::cout << "2 - several values.\n";
            std::cout << "Your choose: ";
            std::cin >> user;
            if (user == 1) { mode = OneValue; }
            if (user == 2) { mode = SeveralValues; }
        }
        if (mode == Back || mode == Front || mode == OneValue) {
            n = 1;
            value = new T[n];
            std::cout << "Input value for insert: ";
            std::cin >> value[0];
        }
        if (mode == SeveralValues) {
            std::cout << "Input number of values for insert: ";
            std::cin >> n;
            value = new T[n];
            std::cout << "Input values for insert (between space): ";
            for (size_t i = 0; i < n; i++) {
                std::cin >> value[i];
            }
        }
        if (mode == OneValue || mode == SeveralValues) {
            std::cout << "Input position for insert: ";
            std::cin >> pos;
        }
        return value;
    }

    template <typename T>
    T* find(size_t*n, InputSystem::FindMode mode) noexcept
    {
        T* value = nullptr;
        value = new T[1];
        int user;

        std::cout << "Choose insert mode:\n";
        std::cout << "0 - find all,\n";
        std::cout << "1 - find first,\n";
        std::cout << "2 - find last,\n";
        std::cout << "Your choose: ";
        std::cin >> user;

        if (user == 0) { mode = fall; }
        if (user == 1) { mode = ffirst; }
        if (user == 2) { mode = flast; }

        std::cout << "Value to search: ";
        std::cin >> value[0];
        return value;
    }

    template <typename T>
    T* remove(size_t& n, InputSystem::RemoveMode& mode) noexcept
    {
        T* value = nullptr;
        int user;
        std::cout << "Choose remove mode:\n";
        std::cout << "1 - pop back,\n";
        std::cout << "2 - pop front,\n";
        std::cout << "3 - erase,\n";
        std::cout << "4 - remove all,\n";
        std::cout << "5 - remove first.\n";
        std::cout << "6 - remove last.\n";
        std::cout << "7 - remove by index.\n";
        std::cout << "Your choice: ";
        std::cin >> user;
        if (user == 1) { mode = rBack; }
        if (user == 2) { mode = rFront; }
        if (user == 3) { mode = Erase; }
        if (user == 4) { mode = rAll; }
        if (user == 5) { mode = rFirst; }
        if (user == 6) { mode = rLast; }
        if (user == 7) { mode = rIndex; }

        if (mode == rAll || mode == rFirst|| mode == rLast || mode == rIndex) {
            n = 1;
            value = new T[n];
            std::cout << "Input value for remove: ";
            std::cin >> value[0];
        }
        if (mode == Erase){
            std::cout << "Input number of values for delete: ";
            std::cin >> n;
            value = new T[1];
            std::cout << "Input position for delete: ";
        	std::cin >> value[0];
        }
        return value;
    }
}

namespace OutputSystem {
    static void setCursor(int column, int line) {
        COORD coord;
        coord.X = column;
        coord.Y = line;
        SetConsoleCursorPosition(
            GetStdHandle(STD_OUTPUT_HANDLE),
            coord
        );
    }

    static void getCursor(int& column, int& line) noexcept {
        CONSOLE_SCREEN_BUFFER_INFO csbi;

        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            column = csbi.dwCursorPosition.X;
            line = csbi.dwCursorPosition.Y;
        }
        else {
            column = 0;
            line = 0;
        }
    }

    static void done() noexcept {
        std::cout << "Done." << '\n';
    }

    template <typename T>
    void show(const TArchive<T>& archive) noexcept {
        std::cout << "Archive: { ";
        archive.print();
        if (!archive.empty()) {
            // ÒÚË‡ÂÏ ÔÓÒÎÂ‰Ì˛˛ Á‡ÔˇÚÛ˛
            int column, line;
            getCursor(column, line);
            column -= 2;
            setCursor(column, line);
        }
        std::cout << " }\n";
    }
}
