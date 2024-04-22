#include <iostream>
#include "archive.hpp"
#include "utilities.hpp"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    TArchive<int> archive;
    size_t n, pos;
    int* values = nullptr;
    int user;

    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode imode;
    InputSystem::RemoveMode rmode;

    while (!exit) {
        system("cls");
        OutputSystem::show(archive);
        std::cout << "Menu:\n 1. insert,\n 2. find,\n 3. delete,\n 4. clean,\n 0. exit.\nYour choose: ";
        std::cin >> user;
        switch (user) {
        case Actions::EXIT: {
            exit = true;
            break;
        }
        case Actions::INSERT: {
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::insert<int>(n, pos, imode);
            success = false;
            if (imode == InputSystem::InsertMode::Back) {
                try
                {
                    archive.push_back(values[0]);
                    success = true;
                }
                catch (std::exception err)
                {
                    std::cerr << err.what() << '\n';
                }
            }
            else if (imode == InputSystem::InsertMode::Front) {
                try
                {
                    archive.push_front(values[0]);
                    success = true;
                }
                catch (std::exception err)
                {
                    std::cerr << err.what() << '\n';
                }
            }
            else if (imode == InputSystem::InsertMode::OneValue) {
                try {
                    archive.insert(values[0], pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            else if (imode == InputSystem::InsertMode::SeveralValues) {
                try {
                    for (size_t i = 0; i < n; i++)
                        archive.insert(values[i], pos + i);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }

            if (success) {
                OutputSystem::done();
            }
            system("pause");
            break;
        }
        case Actions::FIND: {
            if (values != nullptr) { delete[] values; values = nullptr; }
            success = false;

            if (success) {
                OutputSystem::done();
            }
            system("pause");
            break;
        }
        case Actions::REMOVE: {
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::remove<int>(n, rmode); // rBack, rFront, Erase, rAll, rFirst, rLast, rIndex
            success = false;
            if (rmode == InputSystem::RemoveMode::rBack)
            {
                try
                {
                    archive.pop_back();
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::rFront)
            {
                try
                {
                    archive.pop_front();
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::Erase)
            {
                try {
                    archive.erase(values[0], n);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::rIndex)
            {
                try
                {
                    archive.remove_by_index(values[0]);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::rAll)
            {
                try
                {
                    archive.remove_all(values[0]);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::rFirst)
            {
                try
                {
                    archive.remove_first(values[0]);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << '\n';
                }
            }
            if (rmode == InputSystem::RemoveMode::rLast) {
                {
                    try
                    {
                        archive.remove_last(values[0]); success = true;
                    }
                    catch (std::exception err) {
                        std::cerr << err.what() << '\n';
                    }
                }
            }
            if (success) {
                OutputSystem::done();
            }
            system("pause");
            break;
        }
        case Actions::CLEAN: {
            success = false;
            try {
                archive.clear();
                success = true;
            }
            catch (std::exception err) {
                std::cerr << err.what() << '\n';
            }
            if (success) {
                OutputSystem::done();
            }
            system("pause");
            break;
        }
        }
    }

    return 0;
}
