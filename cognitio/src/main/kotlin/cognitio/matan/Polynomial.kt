package cognitio.matan

import java.math.BigDecimal
import java.math.BigDecimal.*
import java.math.RoundingMode.HALF_UP

class Polynomial {
    fun y(root: BigDecimal): BigDecimal {

        val pieces: MutableList<BigDecimal> = mutableListOf(valueOf(5)!!)
        pieces.add(valueOf(-24)!!.multiply(root)!!)
        pieces.add(valueOf( 17)!!.multiply(root.pow(2)!!)!!)
        pieces.add(valueOf(-11)!!.divide(valueOf(3),2, HALF_UP)!!.multiply(root.pow(3)!!)!!)
        pieces.add(valueOf(  1)!!.divide(valueOf(4),2, HALF_UP)!!.multiply(root.pow(4)!!)!!)

        var result: BigDecimal = ZERO
        for (piece in pieces) {
            result = result.plus(piece)
        }

        return result
    }

    fun experiment() {
        val result = valueOf(-11).divide(valueOf(3), 2, HALF_UP)
        if (result.toPlainString() != null)
            println(result.toPlainString())
        else
            println("ничего не пришло")
    }
}
