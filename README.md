Скінчений автомат без виходів: A = <A, S, s<sub>0</sub>, F, f><br>
А = {a, b, c, …} – вхідний алфавіт,<br>
S = {0, 1, 2, …} – множина станів,<br>
s<sub>0</sub>∈S – початковий стан,<br>
F⊆S – множина фінальних (заключних) станів,<br>
f: S×A→S – фунція переходів

Автомат A на вході програми (та на виході, де потрібно) подається у вигляді текстового файлу наступної структури:<br>
|A|<br>
|S|<br>
s0<br>
|F| fs1∈F … fs||F||∈F    	// перелічені через проміжок кількість та всі стани з множини F<br>
s a s'  // всі такі трійки, що (s, a, s') ∈ f, через проміжок, по одній на рядок – до кінця файлу.

Розробити та реалізувати представлення скінченого автомата в пам`яті ЕОМ та виконати наступну задачу:<br>
2. Виявити недосяжні та тупикові стани скінченого автомату.

