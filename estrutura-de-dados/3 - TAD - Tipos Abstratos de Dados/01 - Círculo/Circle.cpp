// Implementar
#include "Circle.h"


Circle::Circle()
    : m_radius(1) 
    {
    m_center.setX(0);
    m_center.setY(0);
    }


Circle::Circle(Point &center, double radius) 
    : m_center(center), m_radius(radius) {}
    
//Setters
void Circle::setRadius(double rad){
    m_radius = rad;
}
void Circle::setCenter(Point& p){
    m_center = p;
}

// Getters 
double Circle::getRadius(){
    return m_radius;
}

Point& Circle::getCenter(){
    return m_center;
}

double Circle::area(){
    constexpr double PI = 3.14159265358979323846;
    return (PI * m_radius * m_radius); 
}

bool Circle::contains(Point &p){
    // Se a distancia de d(p, m_center) <= m_radius, então está contido retorna true;
    if (m_center.distance(p) <= m_radius)
        return true;
    
    return false;    
    
    
}

