#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int GRID_DIMENSION = 20;
const int GRID_UPPER_LIMIT = 19;
const int GRID_LOWER_LIMIT = 0;
const int NUM_ANTS = 100;
const int NUM_DOODLES = 5;

class Coords
{
public:
    int x_coord;
    int y_coord;
    Coords(){};
    Coords(int x, int y) : x_coord(x), y_coord(y){};
    ~Coords(){};
};
class Organism
{
public:
    Organism(char sym) : position(Coords(rand() % GRID_DIMENSION, rand() % GRID_DIMENSION)), symbol(sym){};
    Organism(char sym, int x, int y) : position(x, y), symbol(sym){};
    Organism(){};
    int get_position_x() { return position.x_coord; };
    int get_position_y() { return position.y_coord; };
    char get_symbol() { return symbol; };
    void set_position_x(int x)
    {
        if (x > GRID_UPPER_LIMIT || x < GRID_LOWER_LIMIT)
        {
            return;
        }
        else
        {
            position.x_coord = x;
        }
    };
    void set_position_y(int y)
    {
        if (y > GRID_UPPER_LIMIT || y < GRID_LOWER_LIMIT)
        {
            return;
        }
        else
        {
            position.y_coord = y;
        }
    };
    virtual void move()
    {
        int direction = (rand() % 4);
        // top
        if (direction == 0)
        {
            set_position_y(get_position_y() - 1);
        }
        // right
        else if (direction == 1)
        {
            set_position_x(get_position_x() + 1);
        }
        // bottom
        else if (direction == 2)
        {
            set_position_y(get_position_y() + 1);
        }
        // left
        else
        {
            set_position_x(get_position_x() - 1);
        }
    }

private:
    Coords position;
    char symbol;
};
class Ant : public Organism
{
public:
    Ant(int x, int y) : Organism('o', x, y), breed_timer(3){};
    Ant() : Organism('o'), breed_timer(3){};
    void set_breed_timer(int b) { breed_timer = b; }
    int get_breed_timer() { return breed_timer; }
    void move()
    {
        int direction = (rand() % 4);
        // top
        if (direction == 0)
        {
            set_position_y(get_position_y() - 1);
        }
        // right
        else if (direction == 1)
        {
            set_position_x(get_position_x() + 1);
        }
        // bottom
        else if (direction == 2)
        {
            set_position_y(get_position_y() + 1);
        }
        // left
        else
        {
            set_position_x(get_position_x() - 1);
        }
    }

private:
    int breed_timer;
};
class Doodlebug : public Organism
{
public:
    Doodlebug(int x, int y) : Organism('X', x, y), breed_timer(8), starve_timer(3){};
    Doodlebug() : Organism('X'), breed_timer(8), starve_timer(3){};
    void set_breed_timer(int b) { breed_timer = b; };
    int get_breed_timer() { return breed_timer; };
    void set_starve_time(int s) { starve_timer = s; };
    int get_starve_timer() { return starve_timer; };
    void move()
    {
        int direction = (rand() % 4);
        // top
        if (direction == 0)
        {
            set_position_y(get_position_y() - 1);
        }
        // right
        else if (direction == 1)
        {
            set_position_x(get_position_x() + 1);
        }
        // bottom
        else if (direction == 2)
        {
            set_position_y(get_position_y() + 1);
        }
        // left
        else
        {
            set_position_x(get_position_x() - 1);
        }
    }

private:
    int breed_timer;
    int starve_timer;
};
class Garden
{
public:
    Garden(){};
    Organism *grid[GRID_DIMENSION][GRID_DIMENSION];
    vector<Ant *> ants;
    vector<Doodlebug *> doodles;
    void populate();
    void repopulate();
    void spawnOrganisms();
    void printGarden();
    void moveDoodles();
    void moveAnts();
    ~Garden();
};
void Garden::populate()
{
    for (int i = 0; i < GRID_DIMENSION; i++)
    {
        for (int j = 0; j < GRID_DIMENSION; j++)
        {
            grid[i][j] = nullptr;
        }
    }
    for (int i = 0; i < ants.size(); i++)
    {
        if (grid[ants[i]->get_position_x()][ants[i]->get_position_y()] == nullptr)
        {
            grid[ants[i]->get_position_x()][ants[i]->get_position_y()] = ants[i];
        }
        else
        {
            ants[i]->set_position_x(rand() % GRID_DIMENSION);
            ants[i]->set_position_y(rand() % GRID_DIMENSION);
            i--;
        }
    }
    for (int i = 0; i < doodles.size(); i++)
    {
        if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] == nullptr)
        {
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
        }
        else
        {
            doodles[i]->set_position_x(rand() % GRID_DIMENSION);
            doodles[i]->set_position_y(rand() % GRID_DIMENSION);
            i--;
        }
    }
};
void Garden::repopulate()
{
    for (int i = 0; i < GRID_DIMENSION; i++)
    {
        for (int j = 0; j < GRID_DIMENSION; j++)
        {
            grid[i][j] = nullptr;
        }
    }
    for (int i = 0; i < ants.size(); i++)
    {
        grid[ants[i]->get_position_x()][ants[i]->get_position_y()] = ants[i];
    }
    for (int i = 0; i < doodles.size(); i++)
    {
        grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
    }
};
void Garden::spawnOrganisms()
{
    for (int i = 0; i < NUM_ANTS; i++)
    {
        Ant *a = new Ant();
        ants.push_back(a);
    }
    for (int i = 0; i < NUM_DOODLES; i++)
    {
        Doodlebug *d = new Doodlebug();
        doodles.push_back(d);
    }
}
void Garden::printGarden()
{
    for (int i = 0; i < GRID_DIMENSION; i++)
    {
        for (int j = 0; j < GRID_DIMENSION; j++)
        {
            if (grid[i][j] == nullptr)
            {
                cout << "- ";
            }
            else
            {
                cout << grid[i][j]->get_symbol() << " ";
            }
        }
        cout << endl;
    }
};
void Garden::moveAnts()
{
    for (int i = ants.size() - 1; i > -1; i--)
    {
        // move ant
        int tempx = ants[i]->get_position_x();
        int tempy = ants[i]->get_position_y();
        int btimer = ants[i]->get_breed_timer();
        ants[i]->move();
        if (grid[ants[i]->get_position_x()][ants[i]->get_position_y()] != nullptr)
        {
            ants[i]->set_position_x(tempx);
            ants[i]->set_position_y(tempy);
        }

        ants[i]->set_breed_timer(btimer - 1);
        // spawn ant
        if (ants[i]->get_breed_timer() == 0)
        {
            // top
            if (ants[i]->get_position_x() - 1 >= GRID_LOWER_LIMIT && grid[ants[i]->get_position_x() - 1][ants[i]->get_position_y()] == nullptr)
            {
                Ant *a = new Ant(ants[i]->get_position_x() - 1, ants[i]->get_position_y());
                ants.push_back(a);
                ants[i]->set_breed_timer(3);
            }
            // right
            else if (ants[i]->get_position_y() + 1 <= GRID_UPPER_LIMIT && grid[ants[i]->get_position_x()][ants[i]->get_position_y() + 1] == nullptr)
            {
                Ant *a = new Ant(ants[i]->get_position_x(), ants[i]->get_position_y() + 1);
                ants.push_back(a);
                ants[i]->set_breed_timer(3);
            }
            // bottom
            else if (ants[i]->get_position_x() + 1 <= GRID_UPPER_LIMIT && grid[ants[i]->get_position_x() + 1][ants[i]->get_position_y()] == nullptr)
            {
                Ant *a = new Ant(ants[i]->get_position_x() + 1, ants[i]->get_position_y());
                ants.push_back(a);
                ants[i]->set_breed_timer(3);
            }
            // left
            else if (ants[i]->get_position_y() - 1 >= GRID_LOWER_LIMIT && grid[ants[i]->get_position_x()][ants[i]->get_position_y() - 1] == nullptr)
            {
                Ant *a = new Ant(ants[i]->get_position_x(), ants[i]->get_position_y() - 1);
                ants.push_back(a);
                ants[i]->set_breed_timer(3);
            }
            else
            {
                ants[i]->set_breed_timer(1);
            }
        }
    }
}
void Garden::moveDoodles()
{
    for (int i = doodles.size() - 1; i > -1; i--)
    {
        int tempx = doodles[i]->get_position_x();
        int tempy = doodles[i]->get_position_y();
        int stimer = doodles[i]->get_starve_timer();
        int btimer = doodles[i]->get_breed_timer();
        // deletes ant if nearby
        // top
        if (doodles[i]->get_position_y() - 1 >= GRID_LOWER_LIMIT && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() - 1] != nullptr && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() - 1]->get_symbol() == 'o')
        {
            doodles[i]->set_position_y(tempy - 1);
            for (int j = 0; j < ants.size(); j++)
            {
                if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] == ants[j])
                {
                    delete ants[j];
                    ants.erase(ants.begin() + j);
                    break;
                }
            }
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
            doodles[i]->set_starve_time(3);
        }
        // bottom
        else if (doodles[i]->get_position_y() + 1 <= GRID_UPPER_LIMIT && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() + 1] != nullptr && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() + 1]->get_symbol() == 'o')
        {
            doodles[i]->set_position_y(tempy + 1);
            for (int j = 0; j < ants.size(); j++)
            {
                if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] == ants[j])
                {
                    delete ants[j];
                    ants.erase(ants.begin() + j);
                    break;
                }
            }
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
            doodles[i]->set_starve_time(3);
        }
        // left
        else if (doodles[i]->get_position_x() - 1 >= GRID_LOWER_LIMIT && grid[doodles[i]->get_position_x() - 1][doodles[i]->get_position_y()] != nullptr && grid[doodles[i]->get_position_x() - 1][doodles[i]->get_position_y()]->get_symbol() == 'o')
        {
            doodles[i]->set_position_x(tempx - 1);
            for (int j = 0; j < ants.size(); j++)
            {
                if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] == ants[j])
                {
                    delete ants[j];
                    ants.erase(ants.begin() + j);
                    break;
                }
            }
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
            doodles[i]->set_starve_time(3);
        }
        // right
        else if (doodles[i]->get_position_x() + 1 <= GRID_UPPER_LIMIT && grid[doodles[i]->get_position_x() + 1][doodles[i]->get_position_y()] != nullptr && grid[doodles[i]->get_position_x() + 1][doodles[i]->get_position_y()]->get_symbol() == 'o')
        {
            doodles[i]->set_position_x(tempx + 1);
            for (int j = 0; i < ants.size(); j++)
            {
                if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] == ants[j])
                {
                    delete ants[j];
                    ants.erase(ants.begin() + j);
                    break;
                }
            }
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = doodles[i];
            doodles[i]->set_starve_time(3);
        }
        // starve timer
        else
        {
            doodles[i]->set_starve_time(stimer - 1);
        }

        if (doodles[i]->get_starve_timer() == 0)
        {
            grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] = nullptr;
            delete doodles[i];
            doodles.erase(doodles.begin() + i);
        }
        // Otherwise move as normal making sure another doodle or out of bounds
        doodles[i]->move();
        if (grid[doodles[i]->get_position_x()][doodles[i]->get_position_y()] != nullptr)
        {
            doodles[i]->set_position_x(tempx);
            doodles[i]->set_position_y(tempy);
        }
        // spawn doodles
        doodles[i]->set_breed_timer(btimer - 1);
        if (doodles[i]->get_breed_timer() == 0)
        {
            // top
            if (doodles[i]->get_position_x() - 1 >= GRID_LOWER_LIMIT && grid[doodles[i]->get_position_x() - 1][doodles[i]->get_position_y()] == nullptr)
            {
                Doodlebug *a = new Doodlebug(doodles[i]->get_position_x() - 1, doodles[i]->get_position_y());
                doodles.push_back(a);
                doodles[i]->set_breed_timer(8);
            }
            // right
            else if (doodles[i]->get_position_y() + 1 <= GRID_UPPER_LIMIT && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() + 1] == nullptr)
            {
                Doodlebug *a = new Doodlebug(doodles[i]->get_position_x(), doodles[i]->get_position_y() + 1);
                doodles.push_back(a);
                doodles[i]->set_breed_timer(8);
            }
            // bottom
            else if (doodles[i]->get_position_x() + 1 <= GRID_UPPER_LIMIT && grid[doodles[i]->get_position_x() + 1][doodles[i]->get_position_y()] == nullptr)
            {
                Doodlebug *a = new Doodlebug(doodles[i]->get_position_x() + 1, doodles[i]->get_position_y());
                doodles.push_back(a);
                doodles[i]->set_breed_timer(8);
            }
            // left
            else if (doodles[i]->get_position_y() - 1 >= GRID_LOWER_LIMIT && grid[doodles[i]->get_position_x()][doodles[i]->get_position_y() - 1] == nullptr)
            {
                Doodlebug *a = new Doodlebug(doodles[i]->get_position_x(), doodles[i]->get_position_y() - 1);
                doodles.push_back(a);
                doodles[i]->set_breed_timer(8);
            }
            else
            {
                doodles[i]->set_breed_timer(1);
            }
        }
    }
}
Garden::~Garden()
{
    for (int i = 0; i < GRID_DIMENSION; i++)
    {
        for (int j = 0; j < GRID_DIMENSION; j++)
        {
            delete grid[i][j];
        }
    }
}
class World
{
public:
    World() : time(0), nextTurn(true){};
    int getTime() { return time; };
    void setTime(int t) { time = t; };
    void startWorld();
    ~World(){};

private:
    int time;
    bool nextTurn;
};
void World::startWorld()
{
    Garden newG = Garden();
    newG.spawnOrganisms();
    newG.populate();
    while (nextTurn)
    {
        cout << "World at time " << time << ":" << endl;
        newG.printGarden();
        cout << "Press ENTER to continue, enter anything else to stop" << endl;
        if (cin.get() != '\n')
        {
            nextTurn = false;
            break;
        }
        newG.moveDoodles();
        newG.moveAnts();
        newG.repopulate();
        setTime(time + 1);
    }
};
int main()
{
    srand(time(0));
    World newWorld = World();
    newWorld.startWorld();

    return 0;
}