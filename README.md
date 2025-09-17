Лабораторна робота №1  
Тема: Інструментарій програміста на C (gcc, make, git)  
Мета: Ознайомлення з базовим інструментарієм розробника. Реалізація динамічного масиву (ArrayList) на мові C.  



Структура проєкту
arraylist-c/
├─ src/
│ ├─ arraylist.h # Інтерфейс контейнера
│ ├─ arraylist.c # Реалізація методів
│ └─ main.c # Демонстраційні тести
├─ Makefile # Скрипт збирання
├─ .gitignore
└─ README.md

Запуск:
make run

Реалізовані методи
add(item)
insert(index, item)
remove(index)
set(index, item)
get(index)
size()
