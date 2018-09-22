package com.pinetreeapps.apotd.utils

import com.pinetreeapps.apotd.utils.Date
import platform.Foundation.*

actual open class Date(actual val dayOfMonth: Int, actual val monthOfYear: Int,
                       actual val year: Int) : Comparable<Date> {

    actual fun toDateFormatString(): String = "YYYY-MM-DD".replace("YYYY", year.toString()).replace(
            "MM",
            monthOfYear.toString()).replace("DD", dayOfMonth.toString())

    actual fun addDay(daysToAdd: Int) = addDays(daysToAdd)

    override operator fun compareTo(other: Date): Int =
            compareValuesBy(this, other, Date::year, Date::monthOfYear, Date::dayOfMonth)

    open fun addDays(daysToAdd: Int): Date {
        val dateComponents = NSDateComponents()
        dateComponents.setDay(dayOfMonth.toLong())
        dateComponents.setMonth(monthOfYear.toLong())
        dateComponents.setYear(year.toLong())

        val date = NSCalendar.currentCalendar().dateFromComponents(dateComponents)!!
        val daysToAddComponent = NSDateComponents()
        daysToAddComponent.setDay(daysToAdd.toLong())

        val futureDate =
                NSCalendar.currentCalendar().dateByAddingComponents(daysToAddComponent, date, 0)!!

        return toDate(futureDate)
    }

    fun now(): Date {
        return toDate(NSDate())
    }

    private fun toDate(date: NSDate): Date {
        val calendar = NSCalendar.currentCalendar()
        val components =
                calendar.components(NSYearCalendarUnit or NSMonthCalendarUnit or NSDayCalendarUnit,
                                    date)

        val day = components.day.toInt()
        val month = components.month.toInt()
        val year = components.year.toInt()

        return Date(day, month, year)
    }
}

actual val now get() = Date(0, 0, 0).now()