#include "Particles.h"


// CoordPair

vector<Particle*> Particle::particles;
int Particle::numParticles = 0;

CoordPair::CoordPair() {}

CoordPair::CoordPair(double xCoord, double yCoord): x{xCoord}, y{yCoord} {}

CoordPair::CoordPair(const CoordPair& c) : CoordPair{c.x, c.y} {}

double CoordPair::abs() const {return sqrt(*this * *this);}

CoordPair CoordPair::operator- () const {return CoordPair{-x, -y};}

CoordPair CoordPair::operator+= (const CoordPair& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

CoordPair CoordPair::operator-= (const CoordPair& rhs) {return *this += -rhs;}

CoordPair CoordPair::operator*= (const double& rhs)
{
    this->x *= rhs;
    this->y *= rhs;
    return *this;
}

CoordPair CoordPair::operator/= (const double& rhs)
{
    this->x /= rhs;
    this->y /= rhs;
    return *this;
}

// Coord

Coord::Coord(double x, double y, 
    double vX = 0, double vY = 0, 
    double aX = 0, double aY = 0,
    double t = 0, double m  = 0):
    pos{x, y}, vel{vX, vY}, acc{aX, aY},
    time{t}, mass{m} {};


// Particlem
// Implementation of the class Particle


Particle::Particle(Coord c) : 
    coords{c}, radius{(int) c.mass}, Fl_Widget{(int) c.pos.x, (int) c.pos.y, 2 * radius, 2 * radius} 
    {
        numParticles++;
        particles.push_back(this);
    };

Particle::Particle(double x, double y, double vX = 0, double vY = 0, double m = 10) :
    Particle{Coord{x, y, vX, vY, 0, 0, 0, m}} {};

void Particle::draw()
{
    fl_color(FL_BLACK);
    fl_circle(coords.pos.x, coords.pos.y, coords.mass * 5);
}


// Other functionns
// Operators

CoordPair operator+ (CoordPair lhs, const CoordPair& rhs) {return lhs += rhs;}
CoordPair operator- (CoordPair lhs, const CoordPair& rhs) {return lhs -= rhs;}
CoordPair operator* (CoordPair lhs, const double& rhs) {return lhs *= rhs;}
CoordPair operator* (const double& lhs, CoordPair rhs) {return rhs *= lhs;}
CoordPair operator/ (CoordPair lhs, const double& rhs) {return lhs /= rhs;}
double operator* (const CoordPair& lhs, const CoordPair& rhs) 
{
    return (lhs.x * rhs.x) + (rhs.y * rhs.y);
}


// functions


void startSimulation(int numParticles)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    Fl_Window* win = new Fl_Window{1600, 1000};
    
    for (int i = 0; i < numParticles; i++)
    {
        new Particle(randBetween<double>(10, 1590), randBetween<double>(10, 990),
            randBetween<double>(0, 10) - 5, randBetween<double>(0, 10) - 5, 
            randBetween<double>(0, 10));
    }
    
    win->end();
    win->show();

    auto time = chrono::steady_clock::now();
    
    while(win->shown())
    {
        updateState();
        Fl::check();
        Fl::redraw();
        win->redraw();
        this_thread::sleep_until(time);
        time += chrono::microseconds((int) 1000000 / 60);
    }


}


void updateState()
{

    CoordPair r;
    Particle* p;
    Particle* q;
    for (int i = 0; i < Particle::numParticles; i++)

    {
        p = Particle::particles[i];
        p->coords.vel += p->coords.acc;
        if (p->coords.pos.x < 0 || p->coords.pos.x > 1600) {p->coords.vel.x = -p->coords.vel.x;}
        if (p->coords.pos.y < 0 || p->coords.pos.y > 1000) {p->coords.vel.y = -p->coords.vel.y;}
        p->coords.pos += p->coords.vel;
        p->coords.acc = CoordPair{0, 0};
        for (int j = 0; j < Particle::numParticles; j++)
        { 
            q = Particle::particles[j];
            if (p == q) {continue;}
            CoordPair r = p->coords.pos - q->coords.pos;
            p->coords.acc += - (G / (r * r)) * (r / r.abs()) * q->coords.mass;
        }
        p->coords.vel *= 0.999;
    }
}

