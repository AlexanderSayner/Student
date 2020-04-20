package stack.of.books

import stack.of.books.logic.BookStack

fun main() {
    val alphabet = listOf("a", "b", "c", "d")
    println("Алфавит: $alphabet")

    val message = listOf("a", "d", "d", "d", "a")
    println("Сообщение: $message")

    val compressor= BookStack(alphabet)
    val word=compressor.compress(message)

    println("Получается: ")
    word.forEach {
        print("$it ")
    }

    println("\nРасшифровка: ")
    val decompressed=compressor.decompress(word)
    decompressed.forEach {
        print("$it ")
    }
}
