package com.pinetreeapps.apotd.utils

import org.joda.time.format.DateTimeFormat
import org.joda.time.DateTime as JodaDateTime

actual class Date(private val date: JodaDateTime) : Comparable<Date> {

    constructor(day: Int, month: Int, year: Int) : this(JodaDateTime(year, month, day, 0, 0, 0))

    actual val dayOfMonth: Int
        get() = date.dayOfMonth
    actual val monthOfYear: Int
        get() = date.monthOfYear
    actual val year: Int
        get() = date.year

    actual fun toDateFormatString(): String = date.toString(format)

    actual fun addDay(daysToAdd: Int) = Date(date.plusDays(daysToAdd))

    override operator fun compareTo(other: Date): Int =
            compareValuesBy(this, other, Date::year, Date::monthOfYear, Date::dayOfMonth)

    override fun toString(): String = toDateFormatString()

    override fun equals(other: Any?): Boolean = other is Date && other.date == date

    override fun hashCode(): Int = date.hashCode()

    private val format = DateTimeFormat.forPattern("YYYY-MM-dd")
}

actual val now
    get() = Date(JodaDateTime())