package sandbox.cognitio

import sandbox.cognitio.encoding.method.book.stack.BookStack
import sandbox.cognitio.encoding.method.huffman.Huffman

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

fun main() {
    val huffman = Huffman()
    huffman.frequency()
            .forEach { (t, u) -> println("$t : $u") }
//    val tree = Node(1)
//    tree.left = Node(2)
//    tree.left!!.left = Node(5)
//    tree.right = Node(3)
//    println(tree.toString())
    println(huffman.tree(huffman.getNodeTree(huffman.frequency())).toString())
}
