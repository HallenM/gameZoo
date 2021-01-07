# gameZoo

Суть задания
В этой задаче вы играете роль смотрителя зоопарка. В вашем ведении находится N клеток,
в каждой из которых живут животные какого-то одного вида. Плюс у вас есть склад, где хранятся
еда и питье нескольких сортов. Каждое животное ест определённый вид еды. Если еды в клетке
недостаточно, часть животных погибает. Если еды в избытке, то животные приносят потомство.
Каждый ход необходимо на своё усмотрение распределять еду по клеткам и следить за сытостью
и благополучием своих питомцев.

Ход игры
При старте приложения пользователь вводит число клеток, и они заполняются случайным
количеством случайных животных. Животные могут повторяться, то есть может быть несколько
клеток с зебрами. В каждой клетке расположены животные одного типа.
В начале каждого хода игра выводит на экран текущее состояние зоопарка. Например:
Enclosure 1: Zebra. Quantity: 20. Eat: hay. Food: no.
Enclosure 2: Lion. Quantity: 3. Eat: meat. Food: no.
Enclosure 3: Parrot. Quantity: 7. Eat: grain. Food: no.
После этого пользователь может выбрать действие. В базовой версии доступно одно действие:
перенести некоторое количество определённого вида еды со склада в клетку. Команда выглядит так:
move 20 hay to 1. После выполнения данной команды состояние зоопарка будет выведено снова.
Нижние две строчки будут точно такие же, как раньше, но верхняя строка будет выглядеть так:
Enclosure 1: Zebra. Quantity: 20. Eat: hay. Food: 20 hay.
Если после этого повторить эту команду, то в первом вольере будет уже 40 единиц сена. Если
после этого выполнить команду move 20 meat to 1, то в первом вольере будет И сено, И мясо
одновременно.
Когда пользователь закончит все свои действия по кормлению животных, он может завершить
ход командой next. Результатом работы данной команды будет новое состояние зоопарка после
проведения всех расчётов. Расчёты выполняются по следующим правилам:
1. Каждое животное съедает минимальную необходимую ему порцию еды. Те животные, кому
не досталось минимальной порции, умирают от голода.
2. Если после того, как все животные накормлены, в клетке осталась еда нужного типа, то каждое
животное (пока не кончится еда) съедает дополнительно двойную порцию и с вероятностью 30%
приносит потомство, увеличивая количество животных в вольере на 1. Приплод начинает есть
и размножаться только на следующем ходу.
3. Вся неиспользованная еда пропадает.
Пример просчёта конца хода (зебра ест 2 единицы сена, лев ест 1 единицу мяса):
Enclosure 1: Zebra. Quantity: 5. Eat: hay. Food: 3 hay, 10 meat.
Enclosure 2: Lion. Quantity: 3. Eat: meat. Food: 15 meat.
► Next
4 Zebras starved to death.
1 Lion spawned in Enclosure 2.
Enclosure 1: Zebra. Quantity: 1. Eat: hay. Food: no
Enclosure 2: Lion. Quantity: 4. Eat: meat. Food: no
► _

Дополнительные задания к Задаче
— Сделать ограниченное количество еды на складе. В этом случае после каждого перемещения
приложение также должно выводить остатки на складе еды каждого из типов;
— добавить возможность переносить еду не только со склада в клетки, но и из клеток на склад,
а также из одной клетки в другую;
— дать животным возможность употреблять несколько типов еды. Чтобы, например, обезьяна
для насыщения съедала либо 4 фрукта, либо 6 травы, либо 2 мяса. Соответственно, надо
рассмотреть возможность, когда в клетке не хватает мяса на всех, и часть обезьян ест мясо,
а часть – фрукты;
— сделать так, чтобы в одной клетке могли жить животные разных типов. В этом случае
и голодание, и размножение будет рассчитываться для каждого типа независимо (но если
они питаются одним и тем же, то и еду они будут брать из одной кучи. Поэтому в таком случае
сначала животные всех типов должны наесться, и, только если после этого останется лишняя
еда, они будут размножаться);
— «Весёлая ферма»! Животных можно продавать, улучшая своё благосостояние. Но и чтобы
заполнить склад едой до максимума, тоже надо заплатить денег;
— добавить животным возраст. У первоначального населения зоопарка возраст выбирается
случайно, у родившихся в процессе игры возраст устанавливается в 0. Каждый ход возраст
каждого животного увеличивается на 1, и после достижения максимального возраста
(своего для каждого вида животных) каждый ход с вероятностью 50% животное может умереть
от старости, о чём выводится соответствующее сообщение;
— сделать цветной текст в консоли, чтобы играть было веселее.

Если вы не хотите или не можете сами придумать весёлых животных для своего зоопарка, можете
воспользоваться данной таблицей:

Животное  Еда   Минимальное количество еды Максимальный возраст Цена для продажи
Lion      meat                4                      20               300
Tiger     meat                3                      30               300
Cow       hay                 4                      25               400  
Sheep     hay                 2                      15               200
Elefant   hay                 18                     70               500
Monkey    fruit               3                      50               200
Parrot    grain               1                      5                100

Для покупки пищи следует воспользоваться следующей таблицей:

Тип еды     Цена за 10 штук
meat             300
hay              200
fruit            150
grain            100
