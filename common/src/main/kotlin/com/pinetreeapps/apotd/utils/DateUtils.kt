package com.pinetreeapps.apotd.utils

expect class Date : Comparable<Date> {
    val dayOfMonth: Int
    val monthOfYear: Int
    val year: Int
    fun addDay(daysToAdd: Int): Date
    fun toDateFormatString(): String
}

expect val now: Date
