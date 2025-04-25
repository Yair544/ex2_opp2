#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class FormFieldBase {
public:
    virtual ~FormFieldBase() = default;

    // ציור השדה (עם קו קלט, צבעים וכו')
    virtual void draw(sf::RenderWindow& window, sf::Font& font, bool cursorVisible = false) = 0;

    // הפעלת/כיבוי פוקוס
    virtual void setActive(bool active) = 0;

    // טיפול באירועי קלט
    virtual void handleInput(sf::Event event) = 0;

    // עיבוד ולידציה לפי קלט קיים
    virtual void validate() = 0;

    // האם השדה תקין כרגע
    virtual bool isFieldValid() const = 0;

    // תווית השדה (למשל: "ID:")
    virtual std::string getLabel() const = 0;

    // הערך הנוכחי (כפי שהוזן בטופס)
    virtual std::string getValue() const = 0;

    // האם המשתמש לחץ בתוך השדה
    virtual bool containsPoint(const sf::Vector2f& clickPos) const = 0;

    // הזנת ערך ידנית (לשימוש בתסריטים או ברירת מחדל)
    virtual void set(const std::string& str) = 0;

    // הודעת שגיאה מותאמת לשדה (אם השדה לא תקין)
    virtual std::string getErrorMessage() const = 0;

protected:
    std::string label_m;
    sf::Vector2f position_m;
    std::string inputBuffer_m;
    bool isActive_m = false;
};
