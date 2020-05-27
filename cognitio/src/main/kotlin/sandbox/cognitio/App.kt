package sandbox.cognitio

import sandbox.cognitio.algorythm.SeemsLikeAStaticOne
import sandbox.cognitio.algorythm.tree.binary.Node
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

fun huffmanExample(){
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

fun main() {
    println("Стопка книг")
    bookStackExample()
    println("\nПо Хаффману")
    huffmanExample()
}
