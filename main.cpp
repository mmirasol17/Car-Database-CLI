#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>

class CarGUI : public QWidget {
public:
    CarGUI() {
        setWindowTitle("Car Management");
        initUI();
    }

private:
    void initUI() {
        // Create labels
        QLabel* label = new QLabel("Car Management System");
        label->setAlignment(Qt::AlignCenter);

        // Create input fields
        QLabel* year_label = new QLabel("Year:");
        QLineEdit* year_input = new QLineEdit();
        QLabel* brand_label = new QLabel("Brand:");
        QLineEdit* brand_input = new QLineEdit();
        QLabel* model_label = new QLabel("Model:");
        QLineEdit* model_input = new QLineEdit();
        // Create other input fields as needed

        // Create buttons
        QPushButton* add_button = new QPushButton("Add Car");
        QPushButton* search_button = new QPushButton("Search Car");
        // Create other buttons as needed

        // Create layouts
        QVBoxLayout* layout = new QVBoxLayout();
        QHBoxLayout* input_layout = new QHBoxLayout();
        QHBoxLayout* button_layout = new QHBoxLayout();

        // Add labels and input fields to input layout
        input_layout->addWidget(year_label);
        input_layout->addWidget(year_input);
        input_layout->addWidget(brand_label);
        input_layout->addWidget(brand_input);
        input_layout->addWidget(model_label);
        input_layout->addWidget(model_input);
        // Add other input fields as needed

        // Add buttons to button layout
        button_layout->addWidget(add_button);
        button_layout->addWidget(search_button);
        // Add other buttons as needed

        // Add layouts to main layout
        layout->addWidget(label);
        layout->addLayout(input_layout);
        layout->addLayout(button_layout);

        setLayout(layout);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CarGUI window;
    window.show();

    return app.exec();
}
