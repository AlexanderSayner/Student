package stack.of.books.logic

class BookStack(private val alphabet: List<String>) {
    private var _codes: LinkedHashMap<String, String>? = null
    private val codes: LinkedHashMap<String, String>
        get() {
            if (_codes == null) {
                _codes = LinkedHashMap()

                var code = "10"
                var stepCounter = 0
                _codes!![code] = alphabet[stepCounter]
                while (++stepCounter < alphabet.size - 1) {
                    code = "1$code"
                    _codes!![code] = alphabet[stepCounter]
                }
                _codes!![code.replace("0", "1", true)] = alphabet[stepCounter]
            }
            return _codes ?: throw AssertionError("Set to null by another thread")
        }

    init {
        codes.forEach { (letter, code) -> println("$letter : $code") }
    }

    /**
     * Вход - текст, выход - код
     */
    fun compress(message: List<String>): List<String> {

        // Список отвечает за упорядоченность пар
        var stack = codes.toList()
        // Результатирующее кодовое слово
        val word = mutableListOf<String>()

        var isFirstStep = true

        message.forEach { letter ->
            if (!isFirstStep && stack[0].second == letter) {
                word.add("0")
            } else {
                isFirstStep = false
                stack = stack.sortedWith(Comparator { pair1, pair2 ->
                    when {
                        pair1.second == letter -> -1
                        pair2.second == letter -> 1
                        else -> 0
                    }

                })
//                println("Проход по букве $letter")
//                stack.forEach { pair: Pair<String, String> -> println(pair.first + " : " + pair.second) }
                // Записываю соответстующий букве код
                word.add(stack[0].first)
            }
        }

        return word
    }

    /**
     * Расшифровка тривиальна
     */
    fun decompress(compressed: List<String>): List<String> {

        val result = mutableListOf<String>()
        var codeBuffer = ""
        for (code in compressed) {
            if (code == "0") {
                result.add(codeBuffer)
            } else
                codes[code]?.let {
                    result.add(it)
                    codeBuffer = it
                }
        }

        return result
    }
}
