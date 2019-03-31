#pragma once

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <iostream>
#include <math.h>
#include <vector>

using namespace::std;

constexpr double G = 10000;

struct CoordPair
{
    double x, y;
    
    CoordPair();
    CoordPair(double xCoord, double yCoord);
    CoordPair(const CoordPair& c);

    double abs() const;

    CoordPair operator- () const;

    CoordPair operator+= (const CoordPair& rhs);
    CoordPair operator-= (const CoordPair& rhs);
    CoordPair operator*= (const double& rhs);
    CoordPair operator/= (const double& rhs);
    CoordPair operator*= (const CoordPair& rhs);
    
    friend CoordPair operator+ (CoordPair lhs, const CoordPair& rhs);
    friend CoordPair operator- (CoordPair lhs, const CoordPair& rhs);
    friend CoordPair operator* (CoordPair lhs, const double& rhs);
    friend CoordPair operator* (const double& lhs, CoordPair rhs);
    friend CoordPair operator/ (CoordPair lhs, const double& rhs);
    friend double operator* (const CoordPair& lhs, const CoordPair& rhs);
    
};


struct Coord
{
    CoordPair pos, vel, acc;
    double time;
    
    Coord(double x, double y);
    Coord(double x, double y, double vX, double vY, double aX, double aY);
};


class Particle : public Fl_Widget
{
    private:
        int radius = 20;
        Coord coords;
        
    public:
        Particle(double x, double y);
        Particle(double x, double y, double vX, double vY);
        Particle(Coord c);

        static vector<Particle*> particles;
        static int numParticles;

        void draw();

    friend void updateState();
};

void updateState();
