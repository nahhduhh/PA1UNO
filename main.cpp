#include <iostream>
#include "List.h"
#include "Player.h"
#include "Card.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::unique_ptr<List<Player>> game = makeList<Player>();

    game->addFront(new Player(1, "Wardell"));
    game->addFront(new Player(2, "Deacon Blues"));
    game->addFront(new Player(3, "Obama"));
    game->print();

    game->addAnywhere(1, new Player(4,"Nada"));
    game->print();

    game->reverse();
    game->print();

    game->deleteAnywhere(3);
    game->print();

    std::unique_ptr<List<Player>> newjoiners = makeList<Player>();
    newjoiners->addFront(new Player(5,"IDK!!"));
    newjoiners->addFront(new Player(6,"Mazda3 Hatchback"));
    game->concat(newjoiners.get());
    game->print();





    Player* p1 = new Player(1, "player 1");
    std::cout << *p1 << std::endl;
    Card* c1 = new Card("Red" , "Skip");
    Card* c2 = new Card("Blue", "7");

    p1-> drawCard(c1);
    p1-> drawCard(c2);

    Card* played = p1->playCard();
    std::cout << "player played a: " << *played << std::endl;

    return 0;
}
