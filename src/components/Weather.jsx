import React, { useState } from "react";
import axios from "axios";
import "./Weather.css";
import SearchBar from "./SearchBar";
import CurrentWeather from "./CurrentWeather";
import ForecastTable from "./ForecastTable";

const Weather = () => {
    const [city, setCity] = useState("");
    const [weather, setWeather] = useState(null);
    const [error, setError] = useState(null);
    const [loading, setLoading] = useState(false);

    const fetchWeather = async (cityName) => {
        try {
            setLoading(true);
            setError(null);
            const response = await axios.get(
                `https://wttr.in/${cityName}?format=j1`
            );
            setWeather(response.data);
        } catch (err) {
            setError("Nie znaleziono miasta. Spróbuj ponownie.");
            setWeather(null);
        } finally {
            setLoading(false);
        }
    };

    return (
        <div className="weather-container">
            <SearchBar setCity={setCity} fetchWeather={fetchWeather} />

            {error && <p className="error-message">{error}</p>}

            {loading && (
                <div className="loader">Ładowanie...</div>
            )}
            
            {weather && !loading && (
                <>
                    <CurrentWeather city={city} currentCondition={weather.current_condition[0]}/>
                    <ForecastTable forecast={weather.weather} />
                </>
            )}
        </div>
    );
};

export default Weather;