package com.amazonaws.services.lambda.runtime.events.models;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;

/**
 * Class that represents Http Headers.
 * <br>
 * Not using a standard map, because we need insensitive case.
 */
public class HttpHeaders<T> implements Map<String, T> {

    // Headers are case insensitive (https://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4.2)
    private Map<String, T> map = new TreeMap<>(String.CASE_INSENSITIVE_ORDER);

    @Override
    public int size() {
        return map.size();
    }

    @Override
    public boolean isEmpty() {
        return map.isEmpty();
    }

    @Override
    public boolean containsKey(Object key) {
        return map.containsKey(key);
    }

    @Override
    public boolean containsValue(Object value) {
        return map.containsValue(value);
    }

    @Override
    public T get(Object key) {
        return map.get(key);
    }

    @Override
    public T put(String key, T value) {
        return map.put(key, value);
    }

    @Override
    public T remove(Object key) {
        return map.remove(key);
    }

    @Override
    public void putAll(Map<? extends String, ? extends T> m) {
        map.putAll(m);
    }

    @Override
    public void clear() {
        map.clear();
    }

    @Override
    public Set<String> keySet() {
        return map.keySet();
    }

    @Override
    public Collection<T> values() {
        return map.values();
    }

    @Override
    public Set<Entry<String, T>> entrySet() {
        return map.entrySet();
    }

}
