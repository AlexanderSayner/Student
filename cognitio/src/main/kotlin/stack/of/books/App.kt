package stack.of.books

import java.util.*

fun main() {
    val alphabet = listOf("a", "b", "c", "d")
    println("Алфавит: $alphabet")

    val message = listOf("c", "c", "d", "d", "c")
    println("Сообщение: $message")

    val codes = mapOf(alphabet[0] to "0", alphabet[1] to "10", alphabet[2] to "110", alphabet[3] to "111")
    codes.forEach { (letter, code) -> println("$letter : $code") }

    // Список отвечает за упорядоченность пар
    var stack = codes.toList()
    // Результатирующее кодовое слово
    val word = mutableListOf<String>()

    message.forEach { letter ->
        if (stack[0].first == letter) {
            word.add("0")
        } else {
            stack = stack.sortedWith(Comparator<Pair<String, String>> { pair1, pair2 ->
                when {
                    pair1.first == letter -> -1
                    pair2.first == letter -> 1
                    else -> 0
                }

            })
            println("Проход по букве $letter")
            stack.forEach { pair: Pair<String, String> -> println(pair.first + " : " + pair.second) }
            // Записываю соответстующий букве код
            word.add(stack[0].second)
        }
    }

    for (s in word) {
        print("$s ")
    }

    println()
//    val compressor=Compressor(listOf("a", "b", "c", "d"))
}

