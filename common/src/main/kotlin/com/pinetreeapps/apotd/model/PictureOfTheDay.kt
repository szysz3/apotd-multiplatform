package com.pinetreeapps.apotd.model

data class PictureOfTheDay(val date: String, val explanation: String, val media_type: String,
                           val title: String, val url: String)