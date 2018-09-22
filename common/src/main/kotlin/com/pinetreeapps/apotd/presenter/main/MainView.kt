package com.pinetreeapps.apotd.presenter.main

import com.pinetreeapps.apotd.model.PictureOfTheDay
import com.pinetreeapps.apotd.presenter.base.BaseView

interface MainView : BaseView {
    fun showError(errorMessage: String)
    fun showLoading(isLoading: Boolean)
    fun showAPOTD(apotd: PictureOfTheDay)
    fun changeNextButtonState(isEnabled: Boolean)
}
