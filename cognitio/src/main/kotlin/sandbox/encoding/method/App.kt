package sandbox.encoding.method

import sandbox.encoding.method.algorythm.SeemsLikeAStaticOne
import sandbox.encoding.method.algorythm.tree.binary.Node
import sandbox.encoding.method.arithmetic.ArithmeticCoding
import sandbox.encoding.method.book.stack.BookStack
import sandbox.encoding.method.bwt.bwt
import sandbox.encoding.method.huffman.Huffman


fun bookStackExample() {

    val alphabet = listOf("a", "b", "c", "d", "e", "f", "g")
    println("Алфавит: $alphabet")

    val message = listOf("a", "d", "d", "d", "a")
    println("Сообщение: $message")

    val compressor = BookStack(alphabet)
    val word = compressor.compress(message)

    println("Получается: ")
    word.forEach {
        print("$it ")
    }

    println("\nРасшифровка: ")
    val decompressed = compressor.decompress(word)
    decompressed.forEach {
        print("$it ")
    }
    println()
}

fun huffmanExample() {
    val huffman = Huffman()
    huffman.frequency()
            .forEach { (t, u) -> println("$t : $u") }
    val tree: Node<String> = huffman.tree(huffman.getNodeTree(huffman.frequency()))!!
    println(tree.toString())
    tree.huffmanCodes("")
    SeemsLikeAStaticOne.print()
    val encodedBytes = huffman.encodeMessage(SeemsLikeAStaticOne.getDictionary(), "beep boop beer!")
    println(huffman.decodeTree(tree, encodedBytes))
}

fun arithmetic() {
    val arithmeticCoding = ArithmeticCoding()
    arithmeticCoding.index()
}

fun main() {
    println("Стопка книг")
    bookStackExample()
    println("\nПо Хаффману")
    huffmanExample()
    println("\nАрифметическое кодирование")
    arithmetic()
    println("\nАлгоритм преобразования")
    bwt()
}
