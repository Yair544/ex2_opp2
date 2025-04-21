//
//#include "FormField.h"
//
//template<typename T>
//FormField<T>::FormField(const std::string& lbl, sf::Vector2f pos, std::function<bool(const T&)> val)
//    : label(lbl), position(pos), validator(val) {
//}
//
//template<typename T>
//void FormField<T>::draw(sf::RenderWindow& window, sf::Font& font, bool cursorVisible) {
//    sf::Text labelText(label, font, 18);
//    labelText.setPosition(position);
//    labelText.setFillColor(sf::Color::Black);
//    window.draw(labelText);
//
//    sf::RectangleShape box(sf::Vector2f(300, 35));
//    box.setPosition(position.x + 160, position.y);
//    box.setFillColor(sf::Color::White);
//    box.setOutlineThickness(2);
//    box.setOutlineColor(isActive ? sf::Color(0, 120, 255) : (isValid ? sf::Color(160, 160, 160) : sf::Color::Red));
//    window.draw(box);
//
//    std::string valStr = toString(value);
//    if (isActive && cursorVisible) valStr += "|";
//    sf::Text valText(valStr, font, 16);
//    valText.setPosition(position.x + 165, position.y + 5);
//    valText.setFillColor(sf::Color::Black);
//    window.draw(valText);
//}
//
//template<typename T>
//void FormField<T>::setActive(bool active) {
//    isActive = active;
//}
//
//template<typename T>
//void FormField<T>::handleInput(sf::Event event) {
//    if (!isActive) return;
//    if constexpr (std::is_same<T, std::string>::value) {
//        if (event.type == sf::Event::TextEntered) {
//            if (event.text.unicode == '\b') {
//                if (!value.empty()) value.pop_back();
//            }
//            else if (event.text.unicode >= 32 && event.text.unicode < 128) {
//                value += static_cast<char>(event.text.unicode);
//            }
//        }
//    }
//}
//
//template<typename T>
//void FormField<T>::validate() {
//    isValid = validator(value);
//}
//
//template<typename T>
//bool FormField<T>::isFieldValid() const {
//    return isValid;
//}
//
//template<typename T>
//std::string FormField<T>::getLabel() const {
//    return label;
//}
//
//template<typename T>
//T FormField<T>::getValue() const {
//    return value;
//}
//
//template<typename T>
//std::string FormField<T>::toString(const std::string& v) const {
//    return v;
//};
