int getInt() {
    while(1) {
        int k;
        std::cin >> k;
        std::cin.ignore(32767, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Input not an integer! Re-enter key: ";
            std::cout << std::endl;
        }
        else return k;
    }
}