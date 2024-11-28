import React, { useState } from "react";

const SearchBar = ({ setCity, fetchWeather }) => {
    const [inputValue, setInputValue] = useState("");

    const handleSubmit = (e) => {
        e.preventDefault();
        setCity(inputValue);
        fetchWeather(inputValue);
        setInputValue("");
    };

    return (
        <form onSubmit={handleSubmit} classname="weather-form">
            <input type="text" value={inputValue} onChange={(e) => setInputValue(e.target.value)}/>
            <button type="submit">Pobierz pogodę</button>
        </form>
    );
};

export default SearchBar;