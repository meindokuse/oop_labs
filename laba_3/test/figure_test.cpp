#include <gtest/gtest.h>
#include "Triangle.hpp"
#include "Hexagon.hpp"
#include "Octagon.hpp"
#include "FigureVector.hpp"

TEST(TriangleTest, ConstructorAndGetters) {
    Triangle t(5.0, 1.0, 2.0);
    
    auto center = t.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle t(5.0, 0.0, 0.0);
    double area = static_cast<double>(t);
    
    double expected = (3.0 * std::sqrt(3.0) * 25.0) / 4.0;
    EXPECT_NEAR(area, expected, 0.001);
}

TEST(TriangleTest, CopyConstructor) {
    Triangle t1(5.0, 1.0, 2.0);
    Triangle t2 = t1;
    
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, AssignmentOperator) {
    Triangle t1(5.0, 1.0, 2.0);
    Triangle t2;
    t2 = t1;
    
    EXPECT_TRUE(t1 == t2);
}

TEST(HexagonTest, ConstructorAndGetters) {
    Hexagon h(3.0, 1.0, 1.0);
    
    auto center = h.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
    EXPECT_DOUBLE_EQ(center.second, 1.0);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon h(3.0, 0.0, 0.0);
    double area = static_cast<double>(h);
    
    double expected = (3.0 * std::sqrt(3.0) * 9.0) / 2.0;
    EXPECT_NEAR(area, expected, 0.001);
}

TEST(OctagonTest, ConstructorAndGetters) {
    Octagon o(4.0, 2.0, 2.0);
    
    auto center = o.getCenter();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon o(4.0, 0.0, 0.0);
    double area = static_cast<double>(o);
    
    double expected = 2.0 * std::sqrt(2.0) * 16.0;
    EXPECT_NEAR(area, expected, 0.001);
}

TEST(FigureVectorTest, EmptyVector) {
    FigureVector figures;
    
    EXPECT_EQ(figures.getSize(), 0);
    EXPECT_EQ(figures.len(), 0);
}

TEST(FigureVectorTest, AddFigures) {
    FigureVector figures;
    
    figures.push(new Triangle(5.0, 0.0, 0.0));
    figures.push(new Hexagon(3.0, 1.0, 1.0));
    figures.push(new Octagon(4.0, 2.0, 2.0));
    
    EXPECT_EQ(figures.getSize(), 3);
}

TEST(FigureVectorTest, GetFigure) {
    FigureVector figures;
    figures.push(new Triangle(5.0, 0.0, 0.0));
    
    Figure* fig = figures.get(0);
    EXPECT_NE(fig, nullptr);
    
    auto center = fig->getCenter();
    EXPECT_DOUBLE_EQ(center.first, 0.0);
    EXPECT_DOUBLE_EQ(center.second, 0.0);
}

TEST(FigureVectorTest, RemoveFigure) {
    FigureVector figures;
    figures.push(new Triangle(5.0, 0.0, 0.0));
    figures.push(new Hexagon(3.0, 1.0, 1.0));
    
    EXPECT_EQ(figures.getSize(), 2);
    figures.remove(0);
    EXPECT_EQ(figures.getSize(), 1);
    
    Figure* fig = figures.get(0);
    auto center = fig->getCenter();
    EXPECT_DOUBLE_EQ(center.first, 1.0);
}

TEST(FigureVectorTest, TotalAreaCalculation) {
    FigureVector figures;
    
    figures.push(new Triangle(5.0, 0.0, 0.0));
    figures.push(new Hexagon(3.0, 0.0, 0.0));
    
    double total = figures.calculateTotalArea();
    EXPECT_GT(total, 0.0);
    
    double triangleArea = static_cast<double>(*figures.get(0));
    double hexagonArea = static_cast<double>(*figures.get(1));
    EXPECT_NEAR(total, triangleArea + hexagonArea, 0.001);
}

TEST(FigureVectorTest, ClearVector) {
    FigureVector figures;
    
    figures.push(new Triangle(5.0, 0.0, 0.0));
    figures.push(new Hexagon(3.0, 1.0, 1.0));
    
    EXPECT_EQ(figures.getSize(), 2);
    figures.clear();
    EXPECT_EQ(figures.getSize(), 0);
}

TEST(FigureVectorTest, PrintCentersAndAreas) {
    FigureVector figures;
    figures.push(new Triangle(5.0, 0.0, 0.0));
    
    testing::internal::CaptureStdout();
    figures.printAllCentersAndAreas();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_FALSE(output.empty());
}

TEST(PolymorphismTest, DifferentFiguresInVector) {
    FigureVector figures;
    
    figures.push(new Triangle(5.0, 0.0, 0.0));
    figures.push(new Hexagon(3.0, 1.0, 1.0));
    figures.push(new Octagon(4.0, 2.0, 2.0));
    
    for (size_t i = 0; i < figures.getSize(); ++i) {
        Figure* fig = figures.get(i);
        auto center = fig->getCenter();
        double area = static_cast<double>(*fig);
        
        EXPECT_GE(center.first, 0.0);
        EXPECT_GE(center.second, 0.0);
        EXPECT_GT(area, 0.0);
    }
}

TEST(PolymorphismTest, CloneOperation) {
    Triangle original(5.0, 1.0, 2.0);
    Figure* clone = original.clone();
    
    EXPECT_TRUE(original == *clone);
    EXPECT_NE(&original, clone);  
    
    delete clone;
}