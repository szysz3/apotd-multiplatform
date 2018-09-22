package com.pinetreeapps.apotd.presenter.main

import com.pinetreeapps.apotd.dal.PictureOfTheDayRepository
import com.pinetreeapps.apotd.presenter.base.BasePresenter
import com.pinetreeapps.apotd.utils.Date
import com.pinetreeapps.apotd.utils.coroutines.launch
import com.pinetreeapps.apotd.utils.now
import kotlin.coroutines.experimental.CoroutineContext

class MainPresenter(private val uiContext: CoroutineContext,
                    private val repository: PictureOfTheDayRepository) : BasePresenter<MainView>() {

    private var dateForCurrentAPOTD: Date = now

    override fun onViewAttached() {
        super.onViewAttached()
        loadAPOTD(dateForCurrentAPOTD)
    }

    fun showNextAPOTD() {
        dateForCurrentAPOTD = dateForCurrentAPOTD.addDay(1)
        loadAPOTD(dateForCurrentAPOTD)
    }

    fun showPreviousAPOTD() {
        dateForCurrentAPOTD = dateForCurrentAPOTD.addDay(-1)
        loadAPOTD(dateForCurrentAPOTD)
    }

    private fun refreshNavigationState() {
        view?.changeNextButtonState(dateForCurrentAPOTD < now)
    }

    private fun loadAPOTD(forDate: Date) {
        launch(uiContext) {
            refreshNavigationState()
            view?.showLoading(true)
            try {
                val apotd = repository.getAPOTD(forDate)
                if (apotd.media_type == "image") view?.showAPOTD(apotd)
                else view?.showError("Videos are not supported.")
            } catch (e: Throwable) {
                view?.showError(e.message ?: "Cannot load APOTD")
            }
            view?.showLoading(false)
        }
    }
}