#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); // Initialize the Qt application

    QWidget *window = new QWidget(); // Create a main window widget
    window->setWindowTitle("Simple Qt GUI"); // Set window title

    QPushButton *button = new QPushButton("Click Me!"); // Create a button
    
    QVBoxLayout *layout = new QVBoxLayout(); // Create a vertical layout
    layout->addWidget(button); // Add the button to the layout
    window->setLayout(layout); // Set the layout for the window

    QObject::connect(button, &QPushButton::clicked, []() {
        // Lambda function to handle button click
        qDebug("Button clicked!"); // Print a message to the console
    });

    window->show(); // Show the main window
    return app.exec(); // Start the Qt event loop
}