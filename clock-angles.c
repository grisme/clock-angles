#include <stdio.h>
#include <math.h>

/// Данный код реализует вычисление углов между минутной и часовой стрелкой,
/// при условии, что стрелки проходят не строго по делениям, а между делениями
/// Входные данные:
/// -> Текущее количество часов:  от 0 до 23 с unsigned char типом
/// -> Текущее количество минут:  от 0 до 60 c unsigned char типом
/// -> Текущее количество секунд: от 0 до 60 с unsigned char типом
///
/// Выходные данные:
/// <- Угол между минутной и секундной стрелкой в градусах: от 0.0 до 359.0 с float типом

// Вычисляет угол минутной стрелки по минутам и секундам
float minute_arrow_angle(unsigned char minutes, unsigned char seconds){
    float mint_pin_angle = 360.0f / 60;     // Угол между двумя минутными делениями

    // Вычисление точного угла минутной стрелки между делениями
    // Так как минутная стрелка проходит угол между двумя делениями,
    // пока секундная стрелка проходит полный круг - отсюда пропорция
    float additional_angle = seconds * mint_pin_angle / 60;
    float result_angle = mint_pin_angle * minutes + additional_angle;
    return result_angle;
}

// Вычисляет угол часовой стрелки по часам и минутам
float hour_arrow_angle(unsigned char hours, unsigned char minutes){
    float hour_pin_angle = 360.0f / 12;     // Угол между двумя часовыми делениями
    if (hours >= 12) hours -= 12;

    // Вычисление точного угла часовой стрелки между делениями
    // Так как часовая стрелка проходит угол между двумя делениями,
    // пока минутная стрелка проходит полный круг - отсюда пропорция
    float additional_angle = minutes * hour_pin_angle / 60;
    float result_angle = hour_pin_angle * hours + additional_angle;
    return result_angle;

}

// Вычисляет угол между минутной и часовой стрелкой
float hour_minute_arrows_angle(unsigned char hours, unsigned char minutes, unsigned char seconds){
    // Точный угол часовой стрелки
    float hour_angle = hour_arrow_angle(hours, minutes);

    // Точный угол минутной стрелки
    float mint_angle = minute_arrow_angle(minutes, seconds);

    // Модуль разницы между углами - даст точный угол между минутной и часовой стрелкой
    return fabs(hour_angle - mint_angle);
}

/// Точка входа в приложение
int main()
{
    // Тесты вычисления угла минутной стрелки
    float min_test_1 = minute_arrow_angle(00, 00);  printf("Minutes test 1 : %f\n", min_test_1);
    float min_test_2 = minute_arrow_angle(15, 00);  printf("Minutes test 2 : %f\n", min_test_2);
    float min_test_3 = minute_arrow_angle(30, 00);  printf("Minutes test 3 : %f\n", min_test_3);
    float min_test_4 = minute_arrow_angle(45, 00);  printf("Minutes test 4 : %f\n", min_test_4);
    float min_test_5 = minute_arrow_angle(16, 00);  printf("Minutes test 5 : %f\n", min_test_5);
    printf("--------------\n\n");

    // Тесты вычисления угла часовой стрелки
    float hor_test_1 = hour_arrow_angle(00, 00);    printf("Hours test 1 : %f\n", hor_test_1);
    float hor_test_2 = hour_arrow_angle(15, 00);    printf("Hours test 2 : %f\n", hor_test_2);
    float hor_test_3 = hour_arrow_angle(18, 00);    printf("Hours test 3 : %f\n", hor_test_3);
    float hor_test_4 = hour_arrow_angle(21, 00);    printf("Hours test 4 : %f\n", hor_test_4);
    float hor_test_5 = hour_arrow_angle(16, 30);    printf("Hours test 5 : %f\n", hor_test_5);
    printf("--------------\n\n");

    // Основной тест
    printf("H:M angle for 16:45:33 : %f\n", hour_minute_arrows_angle(16, 45, 33));
    printf("H:M angle for 15:00:00 : %f\n", hour_minute_arrows_angle(15, 00, 00));
    printf("H:M angle for 14:00:00 : %f\n", hour_minute_arrows_angle(14, 00, 00));
    printf("H:M angle for 21:52:30 : %f\n", hour_minute_arrows_angle(21, 52, 30));

    return 0;
}
