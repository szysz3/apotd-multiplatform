import Foundation

import Alamofire
import AstronomyPictureOfTheDay

class ApotdRepository: APOTDPictureOfTheDayRepository {
    
    let baseUrl: String
    let apiKey: String
    let apotdParser: ApotdParser
    
    init(baseUrl: String, apiKey: String, parser: ApotdParser) {
        self.baseUrl = baseUrl
        self.apiKey = apiKey
        self.apotdParser = parser
    }
    
    override func getAPOTD(date: APOTDDate, callback: APOTDStdlibContinuation) {
        var url = baseUrl.appending("apod?api_key=\(apiKey)")
        url = url.appending("&date=\(date.toDateFormatString())")
        
        Alamofire.request(URL(string: url)!)
            .responseJSON { response in
                if let result = self.apotdParser.parse(response: response) {
                    callback.resume(value: result)
                } else {
                    callback.resumeWithException(exception: APOTDStdlibThrowable(message: "Cannot parse APOTD"))
                }
        }
    }
}
