import UIKit
import AstronomyPictureOfTheDay
import Kingfisher

class ViewController: UIViewController, APOTDMainView {
    
    let parser: ApotdParser = ApotdParser()
    var repository: ApotdRepository?
    var presenter: APOTDMainPresenter?
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var image: UIImageView!
    @IBOutlet weak var nextButton: UIButton!
    @IBOutlet weak var previousButton: UIButton!
    @IBOutlet weak var titleLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        repository = ApotdRepository(baseUrl: APOTDConstantsCompanion().apotd_ENDPOINT,
                                     apiKey: APOTDConstantsCompanion().api_KEY,
                                     parser: parser)
        presenter = APOTDMainPresenter(uiContext: APOTDMainQueueDispatcher(), repository: repository!)
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        presenter?.attach(view: self)
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)
        presenter?.detach()
    }
    
    @IBAction func onNextButtonClicked(_ sender: Any) {
        presenter?.showNextAPOTD()
    }
    
    @IBAction func onPreviousButtonClicked(_ sender: Any) {
        presenter?.showPreviousAPOTD()
    }
    
    func showError(errorMessage: String) {
        let alertController = UIAlertController(title: "Error", message:
            errorMessage, preferredStyle: UIAlertControllerStyle.alert)
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler: nil))
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    func showLoading(isLoading: Bool) {
        activityIndicator.isHidden = !isLoading
        previousButton.isEnabled = !isLoading
        nextButton.isEnabled = !isLoading
    }
    
    func showAPOTD(apotd: APOTDPictureOfTheDay) {
        let url = URL(string: apotd.url)
        image.kf.setImage(with: url)
        titleLabel.text = apotd.title
    }
    
    func changeNextButtonState(isEnabled: Bool) {
        nextButton.isHidden = !isEnabled
    }

}

