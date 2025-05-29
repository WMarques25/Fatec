{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE QuasiQuotes       #-}

module Pagina where

import Foundation
import Yesod.Core

getPaginaR :: Handler Html
getPaginaR = defaultLayout $ do
    setTitle "PaginaR"
    [whamlet|
        <p>
            Ola Mundo!
    |]