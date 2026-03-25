class Rectangle {
private:
    double width;
    double height;

public:
    
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    double area() const {
        return width * height;
    }

    double perimeter() const {
        return 2 * (width + height);
    }
};